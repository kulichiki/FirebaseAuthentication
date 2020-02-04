package com.thegetaway.firebaseauthentication;

import com.google.firebase.auth.FirebaseAuth;

public class BaseAuthentication
{
    public static native void NativeFirebaseResultCode(int StatusCode);
    public static native void NativeFirebaseResult();

    public static void FirebaseAccountSignOut()
    {
        FirebaseAuth.getInstance().signOut();
    }
}
