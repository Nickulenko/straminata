<!--Блок отладки-->
<div style="color:white;text-align:center;width:100%;height:200px;">
	<h2>Сайт на реконструкции</h2><br>
	<?php
		$blockstyle = 'border:2px solid white;width:250px;position:relative;float:left;margin:0 20px 0 20px;';
	?>
	<div style="<?=$blockstyle?>">
		<b>Информация о странице</b><br>
		<?php
			echo "GET страница: ";
			print($_GET['p']);
			echo "<br>SESSION страница: ";
			print($_SESSION['p']);
			echo "<br>REQUEST_URI: ";
			print($_SERVER['REQUEST_URI']);
			echo "<br>SERVER_NAME: ";
			print($_SERVER['SERVER_NAME']);
			echo "<br>PHP_SELF: ";
			print($_SERVER['PHP_SELF']);
		?>
	</div>
	<div style="<?=$blockstyle?>">
		<b>Блок 2</b><br>
		<?php
			echo "Поленая информация: ";
			print('');
			echo "<br>Поленая информация: ";
			print('');
		?>
	</div>
	<div style="<?=$blockstyle?>">
		<b>Блок 3</b><br>
		<?php
			echo "Поленая информация: ";
			print('');
			echo "<br>Поленая информация: ";
			print('');
		?>
	</div>
</div>
<br>
<hr>