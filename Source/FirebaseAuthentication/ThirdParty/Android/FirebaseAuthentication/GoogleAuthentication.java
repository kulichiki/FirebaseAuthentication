package com.thegetaway.firebaseauthentication;

import android.app.Activity;
import android.content.Intent;
import android.support.annotation.NonNull;

import com.google.android.gms.auth.api.signin.GoogleSignIn;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.android.gms.auth.api.signin.GoogleSignInClient;
import com.google.android.gms.auth.api.signin.GoogleSignInOptions;
import com.google.android.gms.common.api.ApiException;
import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthCredential;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.GoogleAuthProvider;

public class GoogleAuthentication
{
    private static native void NativeGoogleResult(int Result);
    private GoogleSignInClient SignInClient;
    private FirebaseAuth FirebaseAuthInstance;
    private Activity MainActivity;

    private static final int GOOGLE_SIGNIN_RC = 9001;

    private class ResultCodes
    {
        static final int SUCCESS          = 0;
        static final int UNKNOWN_ERROR    = 1;
    }

    public GoogleAuthentication(Activity MainActivity)
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
        this.MainActivity = MainActivity;

        // Get Web Client ID
        int ResourceID = this.MainActivity.getResources().getIdentifier("default_web_client_id", "string", this.MainActivity.getPackageName());
        String WebClientID = this.MainActivity.getString(ResourceID);

        // Initialize Google Sign In
		GoogleSignInOptions SignInOptions = new GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
											.requestIdToken(WebClientID)
											.requestEmail()
											.build();
		this.SignInClient = GoogleSignIn.getClient(this.MainActivity, SignInOptions);
    }

    public void GoogleSignIn()
    {
        Intent SignInIntent = SignInClient.getSignInIntent();
        MainActivity.startActivityForResult(SignInIntent, GOOGLE_SIGNIN_RC);
    }

    public void GoogleSignOut()
    {
        FirebaseAuthInstance.signOut();
        SignInClient.signOut().addOnCompleteListener(new OnCompleteListener<Void>()
        {
            @Override
            public void onComplete(@NonNull Task<Void> Task)
            {
                NativeGoogleResult(ResultCodes.SUCCESS);
            }
        });
    }

    public void GoogleRevokeAccess()
    {
        FirebaseAuthInstance.signOut();
        SignInClient.revokeAccess().addOnCompleteListener(new OnCompleteListener<Void>()
        {
            @Override
            public void onComplete(@NonNull Task<Void> Task)
            {
                NativeGoogleResult(ResultCodes.SUCCESS);
            }
        });
    }

    // Internal function
    private void FirebaseAuthWithGoogle(GoogleSignInAccount SignInAccount)
    {
        AuthCredential Credential = GoogleAuthProvider.getCredential(SignInAccount.getIdToken(), null);
        FirebaseAuthInstance.signInWithCredential(Credential).addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                    NativeGoogleResult(ResultCodes.SUCCESS);
                else
                    NativeGoogleResult(ResultCodes.UNKNOWN_ERROR);
            }
        });
    }
	
	// ActivityResult
	private void ActivityResult(int RequestCode, Intent Data)
	{
		if (RequestCode == GOOGLE_SIGNIN_RC)
		{
			Task<GoogleSignInAccount> Task = GoogleSignIn.getSignedInAccountFromIntent(Data);
			try
			{
				GoogleSignInAccount SignInAccount = Task.getResult(ApiException.class);
				FirebaseAuthWithGoogle(SignInAccount);
			}
			catch (ApiException e)
			{
				NativeGoogleResult(ResultCodes.UNKNOWN_ERROR);
			}
		}
	}
}
