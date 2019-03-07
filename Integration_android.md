# Mati Android SDK documentation
Our SDK requires Android v5.0 (API v21) or above.

![alt text](https://github.com/MatiFace/mati-global-id-sdk/blob/master/Group%2011.png)

## Gradle configuration

Ensure that your top-level build.gradle contains a reference to the following repository:

    jcenter()
    
Open the build.gradle file inside your application module directory and include the following dependencies into build.gradle file of your app:

    implementation 'com.matilock:mati-global-id-sdk:0.0.7'
    
![alt text](https://github.com/MatiFace/mati-global-id-sdk/blob/master/build.gradle.png?raw=true)
    
Once you make these two changes, simply sync your project with gradle.

    
## Mati SDK initialization

In the onCreate() method of your application class, initialize Mati by calling the following line of code:

    public class MyApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();

        Mati.init(this, "your client ID here");
      }
    }
   
## Mati KYC Button Placement (UI)

You now need to place the Mati KYC button inside your App. Add it to your layout XML file:

    <com.matilock.mati_kyc_sdk.MatiLoginButton
                    android:layout_width="match_parent"
                    android:layout_height="wrap_content"
                    app:text="Custom"/>
                    
## Metadata

Choose what kind of metadata you want to receive as shown in example below.

    Metadata metadata = new Metadata.Builder()
                    .with("userId", "Your Client ID")
                    .with("type", 2)
                    .build();
    
    Mati.getInstance().setMetadata(metadata);

## Callback Registration

In order to handle login responses create a callback manager by calling following code:

    private MatiCallbackManager mCallbackManager = MatiCallbackManager.createNew();

Now register callback to handle callback responses

    MatiLoginManager.getInstance().registerCallback(mCallbackManager, new MatiCallback() {
                @Override
                public void onSuccess(LoginResult pLoginResult) {
                    Log.d(TAG, "User finished verification process successfully!");
                }
    
                @Override
                public void onCancel() {
                    Log.d(TAG, "User cancelled verification flow");
                }
    
                @Override
                public void onError(LoginError pLoginError) {
                    Log.d(TAG, pLoginError.getMessage());
                }
            });

And in your onActivityResult method, call mCallbackManager.onActivityResult to pass the login results to the MatiLoginManger

    @Override
      protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        mCallbackManager.onActivityResult(requestCode, resultCode, data);
        super.onActivityResult(requestCode, resultCode, data);
      }
