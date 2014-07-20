<?php
	session_start();
	/*
		Выбор языка
		if($_SESSION['l'] == '') $_SESSION['l'] = $mainlang;
		if(($_GET['l'] != '') AND ($_SESSION['l'] != $_GET['l'])) $_SESSION['l'] = $_GET['l'];
	*/

	//Выбор страницы
	if(!isset($_GET['p'])) $_GET['p'] = 'home';
	
	$siteadress = 'justbear.org';				// Адрес сайта
	$sitename = 'JUSTBEAR';						// Название сайта
	$companyname = 'JUSTBEAR';					// Название компании
	$template = 'justbear14';					// Название шаблона
	$year = 2014;								// Текущий год
	$mainlang = 'eng';							// Основной язык
	$lang = $mainlang;							// Текущий язык
	$themespath = 'jbadmin/templates';			// Положение шаблонов

	include_once("analyticstracking.php");	// Аналитика Google	
	(@include_once ('jbadmin/templates/'.$template.'/index.php')) OR die("Ошибка: тема не найдена");	// Подключение темы
?>