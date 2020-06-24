# Sample init scripts and service configuration for tradetensord

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/tradetensord.service:    systemd service unit configuration
    contrib/init/tradetensord.openrc:     OpenRC compatible SysV style init script
    contrib/init/tradetensord.openrcconf: OpenRC conf.d file
    contrib/init/tradetensord.conf:       Upstart service configuration file
    contrib/init/tradetensord.init:       CentOS compatible SysV style init script

# Service User

All three startup configurations assume the existence of a "tradetensor" user
and group.  They must be created before attempting to use these scripts.

# Configuration

At a bare minimum, tradetensord requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, tradetensord will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that tradetensord and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If tradetensord is run with `-daemon` flag, and no rpcpassword is set, it will
print a randomly generated suitable password to stderr.  You can also
generate one from the shell yourself like this:

```bash
bash -c 'tr -dc a-zA-Z0-9 < /dev/urandom | head -c32 && echo'
```

Once you have a password in hand, set `rpcpassword=` in `/etc/tradetensor/tradetensor.conf`

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/tradetensor.conf`.

# Paths

All three configurations assume several paths that might need to be adjusted.
```
Binary:              /usr/bin/tradetensord
Configuration file:  /etc/tradetensor/tradetensor.conf
Data directory:      /var/lib/tradetensord
PID file:            /var/run/tradetensord/tradetensord.pid (OpenRC and Upstart)
                     /var/lib/tradetensord/tradetensord.pid (systemd)
```
The configuration file, PID directory (if applicable) and data directory
should all be owned by the tradetensor user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
tradetensor user and group.  Access to tradetensor-cli and other tradetensord rpc clients
can then be controlled by group membership.

# Installing Service Configuration

## systemd

Installing this .service file consists on just copying it to
`/usr/lib/systemd/system` directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run "systemctl start tradetensord" and to enable for system startup run
`systemctl enable tradetensord`

## OpenRC

Rename tradetensord.openrc to tradetensord and drop it in `/etc/init.d`.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/tradetensord start` and configure it to run on startup with
`rc-update add tradetensord`

## Upstart (for Debian/Ubuntu based distributions)

Drop tradetensord.conf in `/etc/init`.  Test by running "service tradetensord start"
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon uitility.

## CentOS

Copy tradetensord.init to `/etc/init.d/tradetensord`. Test by running "service tradetensord start".

Using this script, you can adjust the path and flags to the tradetensord program by
setting the TRADETENSORD and FLAGS environment variables in the file
`/etc/sysconfig/tradetensord`. You can also use the DAEMONOPTS environment variable here.

# Auto-respawn

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
