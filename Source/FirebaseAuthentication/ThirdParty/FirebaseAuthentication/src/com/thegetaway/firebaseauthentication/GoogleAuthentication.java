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

import static com.thegetaway.firebaseauthentication.BaseAuthentication.NativeFirebaseResult;
import static com.thegetaway.firebaseauthentication.BaseAuthentication.NativeFirebaseResultCode;

public class GoogleAuthentication
{
    private static final int GOOGLE_SIGNIN_RC = 9001;

    private GoogleSignInClient SignInClient;
    private FirebaseAuth FirebaseAuthInstance;
    private Activity MainActivity;

    public GoogleAuthentication(Activity MainActivity)
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
        this.MainActivity = MainActivity;

        String WebClientID = this.MainActivity.getString(R.string.default_web_client_id);
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

        // Google sign out
        SignInClient.signOut().addOnCompleteListener(new OnCompleteListener<Void>()
        {
            @Override
            public void onComplete(@NonNull Task<Void> Task)
            {
                NativeFirebaseResult();
            }
        });
    }

    public void GoogleRevokeAccess()
    {
        // Firebase sign out
        FirebaseAuthInstance.signOut();

        // Google revoke access
        SignInClient.revokeAccess().addOnCompleteListener(new OnCompleteListener<Void>()
        {
            @Override
            public void onComplete(@NonNull Task<Void> Task)
            {
                NativeFirebaseResult();
            }
        });
    }

    // Internal Function
    // ВОЗВРАЩАТЬ РЕЗУЛЬТАТ КОД
    private void FirebaseAuthWithGoogle(GoogleSignInAccount SignInAccount)
    {
        AuthCredential Credential = GoogleAuthProvider.getCredential(SignInAccount.getIdToken(), null);
        FirebaseAuthInstance.signInWithCredential(Credential).addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                {
                    // Sign in success
                    NativeFirebaseResultCode(CommonStatusCodes.SUCCESS);
                }
                else
                {
                    // Sign in failed
                    // УЖАСНЫЙ ОБРАБОТЧИК ОШИБОК, БЕРИ ИЗ НОМЕР ОШИБКИ ИЗ EXCEPTION'а
                    NativeFirebaseResultCode(CommonStatusCodes.ERROR);
                }
            }
        });
    }
	
	// Handler
	private void Handler(int RequestCode, Intent Data)
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
				NativeFirebaseResultCode(e.getStatusCode());
			}
		}
	}
}
