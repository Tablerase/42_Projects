# NGINX

<img src="https://www.vectorlogo.zone/logos/nginx/nginx-icon.svg" width="30%" title="NGINX Logo" draggable="false" align="right"/>

## Introduction

NGINX means "Engine X".

### What is NGINX?

NGINX is a free, open-source, high-performance HTTP server and reverse proxy, as well as an IMAP/POP3 proxy server. NGINX is known for its high performance, stability, rich feature set, simple configuration, and low resource consumption.

### How does NGINX work?

NGINX is a web server which can also be used as a **reverse proxy, load balancer, mail proxy and HTTP cache**. The software was created by Igor Sysoev and first publicly released in 2004. A company of the same name was founded in 2011 to provide support and Nginx plus paid software.

### How to install NGINX?

🕸️ [OceanGate - NGINX container Install and Setup](https://www.digitalocean.com/community/tutorials/how-to-run-nginx-in-a-docker-container-on-ubuntu-22-04)

🗂️ [Official - Nginx Docker](https://docs.nginx.com/nginx/admin-guide/installing-nginx/installing-nginx-docker/)

To install NGINX on Debian, you can use the following command:

```bash
sudo apt update
sudo apt install nginx
```

### How to configure NGINX?

The main configuration file for NGINX is located at `/etc/nginx/nginx.conf`. You can edit this file to configure NGINX to suit your needs. You can also create additional configuration files in the `/etc/nginx/conf.d/` directory and include them in the main configuration file.

### How to start NGINX?

To start NGINX, you can use the following command:

```bash
sudo systemctl start nginx
```

### How to stop NGINX?

To stop NGINX, you can use the following command:

```bash
sudo systemctl stop nginx
```

## Configuration

🎬 [Tuto NGINX - freeCodeCamp](https://youtu.be/9t9Mp0BGnyI?feature=shared)

### Conf Files

NGINX configuration files are located in the `/etc/nginx/` directory. The main configuration file is `nginx.conf`, which includes configuration files from the `conf.d` directory. You can create additional configuration files in the `conf.d` directory and include them in the main configuration file.

Prototype:

```nginx
context {
    directive value;
}
```

Example:

```nginx
server {
    listen 80;
    server_name example.com;
    root /var/www/html;
    index index.html;
}
```

<details>
<summary>Default nginx.conf</summary>

```ini
user www-data;
worker_processes auto;
pid /run/nginx.pid;
error_log /var/log/nginx/error.log;
include /etc/nginx/modules-enabled/*.conf;

events {
	worker_connections 768;
	# multi_accept on;
}

http {
	##
	# Basic Settings
	##

	sendfile on;
	tcp_nopush on;
	types_hash_max_size 2048;
	# server_tokens off;

	# server_names_hash_bucket_size 64;
	# server_name_in_redirect off;

	include /etc/nginx/mime.types;
	default_type application/octet-stream;

	##
	# SSL Settings
	##

	ssl_protocols TLSv1 TLSv1.1 TLSv1.2 TLSv1.3; # Dropping SSLv3, ref: POODLE
	ssl_prefer_server_ciphers on;

	##
	# Logging Settings
	##

	access_log /var/log/nginx/access.log;

	##
	# Gzip Settings
	##

	gzip on;

	# gzip_vary on;
	# gzip_proxied any;
	# gzip_comp_level 6;
	# gzip_buffers 16 8k;
	# gzip_http_version 1.1;
	# gzip_types text/plain text/css application/json application/javascript text/xml application/xml application/xml+rss text/javascript;

	##
	# Virtual Host Configs
	##

	include /etc/nginx/conf.d/*.conf;
	include /etc/nginx/sites-enabled/*;
}


#mail {
#	# See sample authentication script at:
#	# http://wiki.nginx.org/ImapAuthenticateWithApachePhpScript
#
#	# auth_http localhost/auth.php;
#	# pop3_capabilities "TOP" "USER";
#	# imap_capabilities "IMAP4rev1" "UIDPLUS";
#
#	server {
#		listen     localhost:110;
#		protocol   pop3;
#		proxy      on;
#	}
#
#	server {
#		listen     localhost:143;
#		protocol   imap;
#		proxy      on;
#	}
#}
```

</details>

### Contexts

NGINX configuration is organized into contexts, which define the scope of the configuration. The main contexts in NGINX are `http`, `server`, and `location`. 
- The `http` context is used to configure global settings for the server, such as the number of worker processes and the location of log files.
- The `server` context is used to configure settings for a specific server block, such as the server name and the location of the root directory.
- The `location` context is used to configure settings for a specific location block, such as the URL to match and the root directory.

#### Location Context

The `location` context is used to configure settings for a specific location block. Location blocks are used to define how NGINX should handle requests for specific URLs. You can use location blocks to define how NGINX should handle requests for specific URLs, such as static files, dynamic content, or proxy requests.

Prototype:

```nginx
location /path {
    directive value;
}
```

##### Root Directive (append)

The `root` directive is used to set the root directory for a location block. The root directory is the base directory for the location block, and NGINX will look for files in this directory when handling requests for the location.

Prototype:

```nginx
location /wanted_path {
    root /path/to/directory;
}
```

- `/wanted_path` is the URL path that NGINX should match. NGINX will look for files in the `/path/to/directory/wanted_path` directory when handling requests for the location.

##### Alias Directive (link)

The `alias` directive is used to set an alias for a location block. The alias is a path that is used to map a URL path to a directory on the server. The alias directive is used to set an alias for a location block. The alias is a path that is used to map a URL path to a directory on the server.

Prototype:

```nginx
location /wanted_path_to_same_directory {
    alias /path/to/directory/wanted_path;
}
```

- `/wanted_path_to_same_directory` is the URL path that NGINX should match. NGINX will look for files in the `/path/to/directory/wanted_path` directory when handling requests for the location.

##### Try Files Directive

The `try_files` directive is used to define a set of files to try when handling requests for a location block. NGINX will try to serve the files in the order they are listed in the directive.

Prototype:

```nginx
location /wanted_path {
    try_files file1 file2 file3;
}
```

- NGINX will try to serve `file1`, `file2`, and `file3` in order when handling requests for the location.

Example:

```nginx
location / {
    try_files $uri $uri/ =404;
}
```

- `$uri` is the requested URI(Uniform Resource Identifier) and `$uri/` is the URI with a trailing slash. The `=404` is the error code that will be returned if none of the files are found.

#### Redirects

NGINX can be used to create redirects for URLs. Redirects are used to send users to a different URL when they request a specific URL. NGINX can be used to create redirects for URLs. Redirects are used to send users to a different URL when they request a specific URL.

```nginx
location /old_path {
    return status_code /new_url;
}
```

- `/old_path` is the URL path that NGINX should match. NGINX will redirect users to `/new_url` when they request the old path.

#### Rewrites

NGINX can be used to rewrite URLs. Rewrites are used to change the URL that is requested by the user. NGINX can be used to rewrite URLs. Rewrites are used to change the URL that is requested by the user.

```nginx
rewrite regex new_url;
```

- `regex` is a regular expression that matches the URL that should be rewritten. NGINX will rewrite the URL to `new_url` when the regular expression matches.

Example:

```nginx
rewrite ^/old_path/(\w+) /new_path/$1;
```

- The regular expression `^/old_path/(\w+)` matches URLs that start with `/old_path/` followed by one or more word characters. NGINX will rewrite the URL to `/new_path/$1`, where `$1` is the value of the first capture group in the regular expression.

#### Error Pages

🔗 [Custom error pages - DigitalOcean](https://www.digitalocean.com/community/tutorials/how-to-configure-nginx-to-use-custom-error-pages-on-ubuntu-22-04)

NGINX can be used to define custom error pages for different HTTP status codes. Error pages are used to display a custom message to the user when an error occurs. NGINX can be used to define custom error pages for different HTTP status codes. Error pages are used to display a custom message to the user when an error occurs.

```nginx
error_page status_code /error_page.html;
```

#### Directory listing

For security reasons, directory listing is disabled by default in NGINX.

However, NGINX can be used to enable directory listing for a location block. Directory listing is used to display a list of files in a directory when there is no index file present. NGINX can be used to enable directory listing for a location block. Directory listing is used to display a list of files in a directory when there is no index file present.

```nginx
location /wanted_path {
    autoindex on;
}
```

### Directives

NGINX configuration is based on a series of directives that are used to configure the server. Directives are used to set parameters that define how NGINX should operate. Directives can be set at the global level, server level, or location level.

### Mime Types

NGINX uses MIME types to determine how to handle different types of files. MIME types are used to identify the type of content that is being served by the server. NGINX uses MIME types to determine how to handle different types of files, such as HTML, CSS, JavaScript, images, and other types of content.

## Load Balancing

NGINX can be used as a load balancer to distribute incoming requests across multiple servers. Load balancing is used to improve the performance, reliability, and scalability of web applications. NGINX can be used as a load balancer to distribute incoming requests across multiple servers. Load balancing is used to improve the performance, reliability, and scalability of web applications.

### Types of Load Balancing

NGINX supports several types of load balancing algorithms, including round-robin, least connections, IP hash, and more. Each algorithm has its own advantages and disadvantages, and the best algorithm to use will depend on the specific requirements of your application.

| Load Balancing Method | Description |
|-----------------------|-------------|
| Round Robin           | Distributes client requests across all servers sequentially. |
| Least Connections     | Directs traffic to the server with the fewest active connections. |
| IP Hash               | The IP address of the client is used to determine which server receives the request. |
| Generic Hash          | Uses a user-defined key to determine how to distribute requests. |
| Least Time            | Directs traffic to the server selected by a formula that combines the fastest response time and fewest active connections. |

### [Load Balancing Configuration](https://docs.nginx.com/nginx/admin-guide/load-balancer/http-load-balancer/)

NGINX load balancing is configured using the `upstream` directive. The `upstream` directive is used to define a group of servers that will receive incoming requests. NGINX load balancing is configured using the `upstream` directive. The `upstream` directive is used to define a group of servers that will receive incoming requests.

Prototype:

```nginx
http {
    upstream backend {
        # Load balancing method (optional, Round Robin is default)
        # least_conn; # Uncomment for Least Connections
        # ip_hash;    # Uncomment for IP Hash

        server server1.example.com; # weight=5; # Uncomment for Weighted Load Balancing
        server server2.example.com; # down;      # Uncomment to mark server as down
        server server3.example.com; # backup;    # Uncomment to mark server as backup
    }

    server {
        listen 80;

        location / {
            proxy_pass http://backend;
        }
    }
}
```

- The `upstream` directive defines a group of servers named `backend` that will receive incoming requests. The `server` directive is used to define the servers in the group.

### [SSL configuration](http://nginx.org/en/docs/http/configuring_https_servers.html)

NGINX can be used to configure SSL for secure connections. SSL is used to encrypt data transmitted between the client and the server. NGINX can be used to configure SSL for secure connections. SSL is used to encrypt data transmitted between the client and the server.

```nginx
server {
    listen 443 ssl;
    server_name example.com;

    ssl_certificate /path/to/certificate.crt;
    ssl_certificate_key /path/to/private.key;
}
```
