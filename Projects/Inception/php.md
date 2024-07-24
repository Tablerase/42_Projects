# PHP

It was originally called **Personal Home Page**, but it now stands for the recursive initialism PHP: **Hypertext Preprocessor**.

PHP is a popular general-purpose scripting language that is especially suited to web development. Fast, flexible and pragmatic, PHP powers everything from your blog to the most popular websites in the world.

## Setup

We need PHP-FPM (FastCGI process manager) and PHP-MySQL to run Wordpress. You can install them with:

```bash
sudo apt-get install php-fpm php-mysql
```

### Configuration

🔗 [PHP Config with Nginx](https://www.php.net/manual/en/install.unix.nginx.php)

Edit the PHP configuration file at `/etc/php/[version]/fpm/php.ini` to change the settings.

Parameters to change:
- `clear_env = no` to allow Nginx to pass environment variables to PHP.
- `cgi.fix_pathinfo = 0` to prevent PHP from executing files outside the document root.
- `listen = 9000` to set the PHP-FPM socket. By default, PHP-FPM listens for connections on a Unix socket, which is suitable for communication between services on the same host. Changing this to listen on TCP port 9000 allows PHP-FPM to accept connections over the network, which is necessary in environments where PHP-FPM and the web server (e.g., Nginx or Apache) are running in separate containers or hosts.

```bash
sed -i 's/listen = \/run\/php\/php8.2-fpm.sock/listen = 9000/' /etc/php/8.2/fpm/pool.d/www.conf
sed -i 's/;clear_env = no/clear_env = no/' /etc/php/8.2/fpm/pool.d/www.conf
sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/' /etc/php/8.2/fpm/php.ini
```

Both modifications are crucial for configuring PHP-FPM to work correctly in a containerized environment, especially when integrating with other services. The use of `sed -i` for in-place editing avoids the need to manually edit these configuration files, streamlining the Docker image build process.