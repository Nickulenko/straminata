<!-- Страница администрации -->
<?php
	session_start();
	if($_SESSION['admstatus'] == '') $_SESSION['admstatus'] = 'offline';
	$rightpass = '1';
	if($_POST['auth_submit'])
	{
		$pass = $_POST['pass'];
		if($pass == '')
		{
			$err = 'Вы не ввели пароль';
		}
		else
		{
			// $pass = md5($_POST['password']);
			if($pass != $rightpass) $err = 'Неправильный пароль';
			else
			{
				$err = 'Правильный пароль';
				include('connect.php');
				$_SESSION['admstatus'] = 'online';
			}
		}
	}
?>
<html>
	<head>
		<title>Страница администрации</title>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<!-- start -->
		<?php
			if($_SESSION['admstatus'] == 'offline') include_once('auth.php');
			else include_once('pages.php');
		?>
		<!-- end -->
	</body>
</html>