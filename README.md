# Samples using Augment SDK  

Please check the official documentation at: [augment.github.io](https://augment.github.io)

## Get started with Android

To get started with the Android Sample it is quite easy:

 - Open the `Android` directory with Android Studio
 - Edit the `com/augment/acmeshop/ACMEShop.java` file adding your credentials
 - Build the App (on a real device) and you're ready to go!


## Get started with iOS

To get started with the iOS Sample it is quite easy:

 - Open `iOS/ACMEShop.xcworkspace` with Xcode
 - Edit the `ACMEShop.swift` file adding your credentials
 - Build the App (on a real device) and you're ready to go!
 
Note: As you may see we use Cocoapods but we decided to include it in the repo so you don't have to worry about this.
If you want you can update it.

## Get started with the web

The Web sample use [Silex](http://silex.sensiolabs.org) micro-framework, it is a PHP framework based on Symfony.

In the end it is not much important as our SDK is only in Javascript, you should only look at theses two importants files:

- `web/views/product.twig`
- `web/views/fallback.twig`

It uses the Twig templating language but you can read it as basic HTML

With this in mind, get started with the Web sample it is quite easy:

 - Open `web` directory with your favorite editor
 - Edit the `config.php`file adding your credentials
 - Start the PHP server with `php -S 127.0.0.1:4001` in the `web/www` directory and navigate to <u>http://localhost:4001</u>
 
 Note: As you may see we use composer but we decided to include it in the repo so you don't have to worry about this.
If you want you can update it.

# Feedbacks

Here at **Augment** we love and value feedback, if you have any suggestion or if you find a bug in these samples, please open an issue.

If you have question that are not covered by the [documentation](https://augment.github.io) neither by these Sample. Please send us an email at: contact@augment.com (subject sould start with `developer:`)
