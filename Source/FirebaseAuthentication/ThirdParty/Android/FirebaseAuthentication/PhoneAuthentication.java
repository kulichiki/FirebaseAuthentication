package com.thegetaway.firebaseauthentication;

import android.app.Activity;
import android.support.annotation.NonNull;

import com.google.android.gms.common.api.CommonStatusCodes;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.FirebaseException;
import com.google.firebase.FirebaseTooManyRequestsException;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseAuthInvalidCredentialsException;
import com.google.firebase.auth.PhoneAuthCredential;
import com.google.firebase.auth.PhoneAuthProvider;

import java.util.concurrent.TimeUnit;

public class PhoneAuthentication
{
    private static native void NativePhoneResult(int Result);
    private String VerificationID;
    private PhoneAuthProvider.ForceResendingToken ResendToken;
    private PhoneAuthProvider.OnVerificationStateChangedCallbacks AuthCallbacks;
    private FirebaseAuth FirebaseAuthInstance;
    private Activity MainActivity;

    private class ResultCodes
    {
        static final int SUCCESS                = 0;
        static final int INVALID_PHONE_NUMBER   = 1;
        static final int SMS_QUOTA              = 2;
        static final int RESEND_TOKEN_NOT_VALID = 3;
        static final int INVALID_CODE           = 4;
        static final int UNKNOWN_ERROR          = 5;
    }

    public PhoneAuthentication(Activity MainActivity)
    {
        this.FirebaseAuthInstance = FirebaseAuth.getInstance();
        this.MainActivity = MainActivity;
		
		// Initialize phone auth callbacks
		this.AuthCallbacks = new PhoneAuthProvider.OnVerificationStateChangedCallbacks()
		{
			@Override
			public void onVerificationCompleted(PhoneAuthCredential Credential)
			{
				// This callback will be invoked in two situations:
				// 1 - Instant verification. In some cases the phone number can be instantly
				//     verified without needing to send or enter a verification code.
				// 2 - Auto-retrieval. On some devices Google Play services can automatically
				//     detect the incoming verification SMS and perform verification without
				//     user action.
				SignInWithPhoneAuthCredential(Credential);
			}
		
			@Override
			public void onVerificationFailed(FirebaseException e)
			{
				// This callback is invoked in an invalid request for verification is made,
				// for instance if the the phone number format is not valid.
				if (e instanceof FirebaseAuthInvalidCredentialsException)
					NativePhoneResult(ResultCodes.INVALID_PHONE_NUMBER);
				else if (e instanceof FirebaseTooManyRequestsException)
					NativePhoneResult(ResultCodes.SMS_QUOTA);
			}
		
			@Override
			public void onCodeSent(@NonNull String AuthVerificationID, @NonNull PhoneAuthProvider.ForceResendingToken Token)
			{
				// The SMS verification code has been sent to the provided phone number, we
				// now need to ask the user to enter the code and then construct a credential
				// by combining the code with a verification ID.
		
				// Save verification ID and resending token so we can use them later
				VerificationID = AuthVerificationID;
				ResendToken = Token;
				NativePhoneResult(ResultCodes.SUCCESS);
			}
		};
    }

    public void StartPhoneNumberVerification(String PhoneNumber, int Timeout)
    {
        PhoneAuthProvider.getInstance().verifyPhoneNumber
        (
            PhoneNumber,                                // Phone number to verify
            Timeout,                                    // Timeout duration
            TimeUnit.SECONDS,                           // Unit of timeout
            MainActivity,                               // Activity (for callback binding)
            AuthCallbacks                               // OnVerificationStateChangedCallbacks
        );
    }

    public void VerifyPhoneNumberWithCode(String Code)
    {
        if (VerificationID != null)
        {
            PhoneAuthCredential Credential = PhoneAuthProvider.getCredential(VerificationID, Code);
            SignInWithPhoneAuthCredential(Credential);
        }
    }

    public void ResendVerificationCode(String PhoneNumber, int Timeout)
    {
        try
        {
            PhoneAuthProvider.getInstance().verifyPhoneNumber
            (
                PhoneNumber,                            // Phone number to verify
                Timeout,                                // Timeout duration
                TimeUnit.SECONDS,                       // Unit of timeout
                MainActivity,                           // Activity (for callback binding)
                AuthCallbacks,                          // OnVerificationStateChangedCallbacks
                ResendToken                             // ForceResendingToken from callbacks
            );
        }
        catch (Exception e)
        {
            NativePhoneResult(ResultCodes.UNKNOWN_ERROR);
        }
    }

    // Internal
    private void SignInWithPhoneAuthCredential(PhoneAuthCredential Credential)
    {
        FirebaseAuthInstance.signInWithCredential(Credential).addOnCompleteListener(new OnCompleteListener<AuthResult>()
        {
            @Override
            public void onComplete(@NonNull Task<AuthResult> Task)
            {
                if (Task.isSuccessful())
                    NativePhoneResult(ResultCodes.SUCCESS);
                else
                {
                    if (Task.getException() instanceof FirebaseAuthInvalidCredentialsException)
                        NativePhoneResult(ResultCodes.INVALID_CODE);
                    else
                        NativePhoneResult(ResultCodes.UNKNOWN_ERROR);
                }
            }
        });
    }
}
