package com.thegetaway.firebaseauthentication;

import android.app.Activity;
import android.content.Intent;
import android.support.annotation.NonNull;

import com.facebook.AccessToken;
import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.FacebookException;
import com.facebook.login.LoginManager;
import com.facebook.login.LoginResult;
import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthCredential;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FacebookAuthProvider;
import com.google.firebase.auth.FirebaseAuth;

import java.util.Arrays;

import static com.thegetaway.firebaseauthentication.BaseAuthentication.NativeFirebaseResultCode;

public class FacebookAuthentication
{
    private static final int FACEBOOK_SIGNIN_RC = 64206;

    private CallbackManager FacebookCallbackManager;
    private FacebookCallback<LoginResult> LoginCallback;
    private FirebaseAuth FirebaseAuthInstance;
    private Activity MainActivity;

    public FacebookAuthentication(Activity MainActivity)
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
		this.MainActivity = MainActivity;

		// Initialize facebook callbacks
		this.FacebookCallbackManager = CallbackManager.Factory.create();
		this.LoginCallback = new FacebookCallback<LoginResult>()
		{
			@Override
			public void onSuccess(LoginResult Result)
			{
				HandleFacebookAccessToken(Result.getAccessToken());
			}
		
			@Override
			public void onCancel()
			{
				// Sign In Failed
				NativeFirebaseResultCode(CommonStatusCodes.ERROR);
			}
		
			@Override
			public void onError(FacebookException error)
			{
				// Sign In Failed
				NativeFirebaseResultCode(CommonStatusCodes.ERROR);
			}
		};
    }

    public void FacebookSignIn()
    {
        String[] ScopeFields = { "email", "public_profile" };
        LoginManager Manager = LoginManager.getInstance();
        Manager.registerCallback(FacebookCallbackManager, LoginCallback);
        Manager.logInWithReadPermissions(MainActivity, Arrays.asList(ScopeFields));
    }

    public void FacebookSignOut()
    {
        FirebaseAuthInstance.signOut();
        LoginManager.getInstance().logOut();
    }

    // Internal function
    private void HandleFacebookAccessToken(AccessToken Token)
    {
        AuthCredential Credential = FacebookAuthProvider.getCredential(Token.getToken());
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
                    NativeFirebaseResultCode(CommonStatusCodes.ERROR);
                }
            }
        });
    }
	
	// Handler
	private void Handler(int RequestCode, int ResultCode, Intent Data)
	{
		if (RequestCode == FACEBOOK_SIGNIN_RC)
			FacebookCallbackManager.onActivityResult(RequestCode, ResultCode, Data);
	}
}
