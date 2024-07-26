# MariaDB

<div style="float: right;">
  <svg xmlns="http://www.w3.org/2000/svg" x="0px" y="0px" width="200" height="200" viewBox="0 0 48 48" align="right" alt="MariaDB Logo">
  <path fill="#006064" d="M47.776,8.156c-0.13-0.107-0.296-0.163-0.465-0.156c-0.463,0-1.062,0.314-1.385,0.483l-0.128,0.065 c-0.541,0.262-1.13,0.41-1.73,0.435c-0.615,0.02-1.146,0.056-1.836,0.128c-4.091,0.421-5.916,3.556-7.674,6.589 c-0.957,1.65-1.946,3.363-3.301,4.672c-0.28,0.272-0.578,0.525-0.892,0.758c-1.402,1.042-3.163,1.787-4.533,2.314 c-1.319,0.504-2.759,0.957-4.15,1.396c-1.275,0.401-2.478,0.781-3.584,1.191c-0.499,0.185-0.923,0.327-1.298,0.452 c-1.008,0.327-1.735,0.578-2.797,1.309c-0.414,0.283-0.83,0.589-1.111,0.818c-0.843,0.673-1.589,1.459-2.217,2.335 c-0.54,0.809-1.164,1.558-1.862,2.235c-0.224,0.219-0.622,0.327-1.218,0.327C6.899,33.509,4.984,33,3.699,33 C1.987,33,0.208,33.627,0,34c0,0,2.911,1.894,3.014,1.996c-0.111,0.164-1.818,2.503-2.002,3.011 c2.494,0.063,3.956-0.306,5.356-0.983c0.406-0.196,0.818-0.398,1.309-0.605c0.818-0.355,1.699-0.921,2.633-1.52 c1.222-0.797,2.501-1.615,3.741-2.01c1.019-0.311,2.081-0.46,3.147-0.442c1.309,0,2.687,0.175,4.016,0.345 c0.99,0.128,2.78,0.148,3.786,0.208c0.269,0.016,1.84,0.034,2.946,0.027C26.758,36.642,25,39,25,39s6,0,8.548-5.781 c0.034-0.067,0.063-0.136,0.096-0.203c1.58-0.377,5.63-2.513,6.706-8.405c0.504-1.712,0.874-3.412,1.2-4.909 c0.389-1.8,0.725-3.343,1.109-3.942c0.604-0.939,1.525-1.574,2.417-2.191c0.121-0.083,0.244-0.164,0.363-0.252 c1.121-0.787,2.235-1.695,2.481-3.389V9.889C48.098,8.626,47.948,8.303,47.776,8.156z"></path>
  </svg>
</div>

MariaDB is a community-developed fork of the MySQL relational database management system intended to remain free under the GNU GPL. Being a fork of a leading open source software system, it is notable for being led by the original developers of MySQL, who forked it due to concerns over its acquisition by Oracle.

## Setup

### Installation

🧑‍🎓 [Guide Setup - DigitalOcean](https://www.digitalocean.com/community/tutorials/how-to-install-mariadb-on-ubuntu-20-04)

#### Ubuntu/Debian

```bash
apt-get install mariadb-server
```

### Configuration

#### Configuration File

⚙️ [MariaDB Configuration File](https://mariadb.com/kb/en/configuring-mariadb-with-option-files/) : The configuration file is where the MariaDB server reads its settings.

🗃️ [List of options of the Config File](https://dev.mysql.com/doc/refman/9.0/en/server-option-variable-reference.html)

Location depends on the system, but it is usually located at `/etc/mysql/my.cnf`. For MariaDB server, the configuration file is `/etc/mysql/mariadb.conf.d/50-server.cnf`.

##### Configuration Options

- `datadir` : The directory where MariaDB stores its data.
- `pid-file` : The file where the server writes the process ID.
- `socket` : The Unix socket file that the server uses for communication with local clients.
- `user` : The MariaDB user that the server runs as.
- `port` : The port number on which the server listens for TCP/IP connections.
- `bind-address` : The IP address to bind to.

##### Example

```ini
[mysqld]
datadir=/var/lib/mysql
socket=/run/mysql/mysql.sock
pid-file=/run/mysql/mysql.pid
user=root
port=3306 # Default port
bind-address= 0.0.0.0 # Listen to all interfaces
```

#### Configuration of Database

Setup the database with user and password.

```sql
-- Create database
CREATE DATABASE IF NOT EXISTS <database>;
-- Create user and grant privileges
CREATE USER IF NOT EXISTS '<user>'@'<host>' IDENTIFIED BY '<password>';
GRANT ALL PRIVILEGES ON <database>.* TO '<user>'@'<host>' IDENTIFIED BY '<password>';
-- Change password of a user
ALTER USER '<root_user>'@'<host>' IDENTIFIED BY '<root_password>';
-- Flush privileges
FLUSH PRIVILEGES;
```

### Usage

<details>
<summary><h4>Command to Access Database</h4></summary>

```bash
docker exec -it <container> mysql -u <user> -p <database>
```

or

```bash
mysql -u <user> -p <database>
```

Exit the database with `exit` command.

</details>