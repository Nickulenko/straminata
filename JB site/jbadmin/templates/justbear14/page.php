<?php
	require($_SERVER['DOCUMENT_ROOT'].'/jbadmin/database/connect.php');
	$p = $_GET['p'];
	$query = "SELECT rus_title_page, rus_text_page, eng_title_page, eng_text_page FROM pages WHERE name_page = '$p'";
	$result=mysql_query($query);
	if (!$result) echo(mysql_error());
	$row = mysql_fetch_array($result, MYSQL_ASSOC);
	printf("
		<h3>%s</h3>%s
		",
		 $row[$lang.'_title_page'],
		 $row[$lang.'_text_page']
		);
	require($_SERVER['DOCUMENT_ROOT'].'/jbadmin/database/disconnect.php');
?>