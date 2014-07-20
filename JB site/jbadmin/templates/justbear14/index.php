<?php
	require('config.php');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
	<head>
		<title><?=$sitename?></title>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="<?='http://'.$siteadress.'/'.$themespath.'/'.$themename.'/style.css'?>">
		<link rel="stylesheet" type="text/css" href="/fonts/Grands/style.css">
		<link rel="stylesheet" type="text/css" href="/fonts/Source Sans Pro/style.css">
		<link rel="shortcut icon" href="<?='http://'.$siteadress.'/'.$themespath.'/'.$themename.'/images/favicon.ico'?>">
	</head>
	<body>
		<?php //(@include_once ('http://'.$siteadress.'/debugging.php')) OR die("Ошибка: файл отладки не найден"); // Блог отладки?>
		<?php require_once('sidebarleft.php');?>													<!-- Левый сайдбар -->
		<div class="content">
			<?php require_once('title.php');?>														<!-- Заголовок -->
			<div class="pagetext">
				<?php require_once('page.php'); ?>
				<?php// include_once($siteadress.'/'.'pages/'.$_SESSION['l'].'/'.$_GET['p'].'.php');?>	<!-- Контент страницы -->
			</div>
		</div>
		<?php require_once('sidebarright.php');?>													<!-- Правый сайдбар -->
	</body>
</html>