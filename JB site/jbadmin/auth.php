<!-- Авторизация -->
<div class="auth">
	<h3>Авторизация</h3><br>
	<form method="POST">
		Пароль<br>
		<input type="password" name="pass"><br>
		<input type="submit" name="auth_submit" value="Войти"><br>
		<?php echo $err; ?>
	</form>
</div>