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
                {
                    // Sign in success
                    NativeEmailPasswordResult(CommonStatusCodes.SUCCESS);
                }
                else
                {
                    // Sign in failed
                    NativeEmailPasswordResult(CommonStatusCodes.ERROR);
                }
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
                {
                    // Sign in success
                    NativeEmailPasswordResult(CommonStatusCodes.SUCCESS);
                }
                else
                {
                    // Sign in failed
                    NativeEmailPasswordResult(CommonStatusCodes.ERROR);
                }
            }
        });
    }

    public void SendEmailVerification()
    {
        // Send verification email
        final FirebaseUser User = FirebaseAuthInstance.getCurrentUser();
        User.sendEmailVerification().addOnCompleteListener(new OnCompleteListener<Void>()
        {
            @Override
            public void onComplete(@NonNull Task<Void> Task)
            {
                if (Task.isSuccessful())
                {
                    // Sign in success
                    NativeEmailPasswordResult(CommonStatusCodes.SUCCESS);
                }
                else
                {
                    // Sign in failed
                    NativeEmailPasswordResult(CommonStatusCodes.ERROR);
                }
            }
        });
    }
}
