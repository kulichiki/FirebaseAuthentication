package com.thegetaway.firebaseauthentication;

import android.support.annotation.NonNull;

import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthCredential;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.EmailAuthProvider;
import com.google.firebase.auth.FirebaseAuth;

import static com.thegetaway.firebaseauthentication.BaseAuthentication.NativeFirebaseResultCode;

public class AnonymousAuthentication
{
    private FirebaseAuth FirebaseAuthInstance;

    public AnonymousAuthentication()
    {
        FirebaseAuthInstance = FirebaseAuth.getInstance();
    }

    public void AnonymousSignIn()
    {
        FirebaseAuthInstance.signInAnonymously().addOnCompleteListener(this, new OnCompleteListener<AuthResult>()
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

    public void AnonymousLinkAccount(String Email, String Password)
    {
        // Create EmailAuthCredential with email and password
        AuthCredential Credential = EmailAuthProvider.getCredential(Email, Password);
        FirebaseAuthInstance.getCurrentUser().linkWithCredential(Credential).addOnCompleteListener(this, new OnCompleteListener<AuthResult>()
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
}