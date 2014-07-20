<?php
	$host="localhost";
	$db_login="h5162_justbear";
	$db_pass="justbear";
	$db_name="h5162_justbear";

	$db=mysql_connect("$host","$db_login","$db_pass") or die(mysql_error());
	if (!$db)
	{
		exit(mysql_error());
		$db_connection = "offline";
	}
	else
	{
		mysql_query("SET NAMES 'utf8';"); 
		mysql_query("SET CHARACTER SET 'utf8';"); 
		mysql_query("SET SESSION collation_connection = 'utf8_general_ci';");
		mysql_select_db("$db_name",$db) or die(mysql_error());					//Выбор БД
		$db_connection = "online";
	}
?>
