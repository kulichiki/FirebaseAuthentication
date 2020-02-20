package com.thegetaway.firebaseauthentication;

import android.support.annotation.NonNull;

import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class EmailPasswordAuthentication
{
    private static native void NativeEmailPasswordResult(int Result);
    private FirebaseAuth FirebaseAuthInstance;

    private class ResultCodes
    {
        static final int SUCCESS          = 0;
        static final int UNKNOWN_ERROR    = 1;
    }

    public EmailPasswordAuthentication()
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
    }

    public void CreateAccount(String Email, String Password)
    {
        FirebaseAuthInstance.createUserWithEmailAndPassword(Email, Password).addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                    NativeEmailPasswordResult(ResultCodes.SUCCESS);
                else
                    NativeEmailPasswordResult(ResultCodes.UNKNOWN_ERROR);
            }
        });
    }

    public void EmailPasswordSignIn(String Email, String Password)
    {
        FirebaseAuthInstance.signInWithEmailAndPassword(Email, Password).addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                    NativeEmailPasswordResult(ResultCodes.SUCCESS);
                else
                    NativeEmailPasswordResult(ResultCodes.UNKNOWN_ERROR);
            }
        });
    }

    public void SendEmailVerification()
    {
        final FirebaseUser User = FirebaseAuthInstance.getCurrentUser();
        if (User != null)
        {
            User.sendEmailVerification().addOnCompleteListener(new OnCompleteListener<Void>()
            {
                @Override
                public void onComplete(@NonNull Task<Void> Task)
                {
                    if (Task.isSuccessful())
                        NativeEmailPasswordResult(ResultCodes.SUCCESS);
                    else
                        NativeEmailPasswordResult(ResultCodes.UNKNOWN_ERROR);
                }
            });
        }
    }
}
