package com.thegetaway.firebaseauthentication;

import com.google.firebase.auth.FirebaseAuth;

public class BaseAuthentication
{
    public static void FirebaseAccountSignOut()
    {
        FirebaseAuth.getInstance().signOut();
    }
}