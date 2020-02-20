package com.thegetaway.firebaseauthentication;

import android.app.Activity;
import android.support.annotation.NonNull;

import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.OAuthProvider;

public class OAuthAuthentication
{
    private static native void NativeOAuthResult(int Result);
    private FirebaseAuth FirebaseAuthInstance;
    private Activity MainActivity;

    private class ResultCodes
    {
        static final int SUCCESS          = 0;
        static final int UNKNOWN_ERROR    = 1;
    }

    public OAuthAuthentication(Activity MainActivity)
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
        this.MainActivity = MainActivity;
    }

    public void OAuthSignIn(String ProviderID)
    {
        FirebaseAuthInstance.startActivityForSignInWithProvider(MainActivity, OAuthProvider.newBuilder(ProviderID, FirebaseAuthInstance).build())
        .addOnSuccessListener(new OnSuccessListener<AuthResult>()
        {
            @Override
            public void onSuccess(AuthResult Result)
            {
                NativeOAuthResult(ResultCodes.SUCCESS);
            }
        })
        .addOnFailureListener(new OnFailureListener()
        {
            @Override
            public void onFailure(@NonNull Exception e)
            {
                NativeOAuthResult(ResultCodes.UNKNOWN_ERROR);
            }
        });
    }
}
