package com.thegetaway.firebaseauthentication;

import android.support.annotation.NonNull;

import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthCredential;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.EmailAuthProvider;
import com.google.firebase.auth.FirebaseAuth;

public class AnonymousAuthentication
{
    private static native void NativeAnonymousResult(int Result);
    private FirebaseAuth FirebaseAuthInstance;

    private class ResultCodes
    {
        static final int SUCCESS          = 0;
        static final int UNKNOWN_ERROR    = 1;
    }

    public AnonymousAuthentication()
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
    }

    public void AnonymousSignIn()
    {
        FirebaseAuthInstance.signInAnonymously().addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                    NativeAnonymousResult(ResultCodes.SUCCESS);
                else
                    NativeAnonymousResult(ResultCodes.UNKNOWN_ERROR);
            }
        });
    }

    public void AnonymousLinkAccount(String Email, String Password)
    {
        // Create EmailAuthCredential with email and password
        AuthCredential Credential = EmailAuthProvider.getCredential(Email, Password);
        FirebaseAuthInstance.getCurrentUser().linkWithCredential(Credential).addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                    NativeAnonymousResult(ResultCodes.SUCCESS);
                else
                    NativeAnonymousResult(ResultCodes.UNKNOWN_ERROR);
            }
        });
    }
}