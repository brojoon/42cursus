<?php
define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'mysql' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define( 'AUTH_KEY', 'jp7gCF6v.rGZ-v2a2yckpWG:Ch};VL0G' );
define( 'SECURE_AUTH_KEY',  'q/LsZ7o40DUNbY[-M3[}UjX9PbJoCef' );
define( 'LOGGED_IN_KEY',    ';,XmcBIGtpJfwjzH{1hsmfE9IxMx:}pj' );
define( 'NONCE_KEY',        'IoeDNB00=Nh2}bX-1U16Rp6VdJ8eoq1L' );
define( 'AUTH_SALT',        '.z[:[WaYK[aTS7HYaZNz=jBB/laJfyJo' );
define( 'SECURE_AUTH_SALT', 'gxxmO,9c-oxGW4F[.elOTm}]B=Z9JkIZ' );
define( 'LOGGED_IN_SALT',   'mziS]i09AbALU/10iXYXO1DzN:Hvj70r' );
define( 'NONCE_SALT',       'm7aAR7ZdUiPf5tqT//Ql;1lPadH}TIBM' );
$table_prefix = 'wp_';
define( 'WP_DEBUG', false );
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
require_once ABSPATH . 'wp-settings.php';
