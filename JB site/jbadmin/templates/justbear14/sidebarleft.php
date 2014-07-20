<div class="sidebarleft">
	<div class="menu">
		<ul>
			<?php
				require($_SERVER['DOCUMENT_ROOT'].'/jbadmin/database/connect.php');
				$sql = "SELECT link_menu, rus_title_menu, eng_title_menu, name_menu FROM menu WHERE 1";
				$result=mysql_query($sql);
				if (!$result) echo(mysql_error());
				$row = array();
				for($i = 1; $i <= mysql_num_rows($result); $i++)
				{
					$row = mysql_fetch_array($result, MYSQL_ASSOC);	
					printf("
						<li><a href='%s'>%s</a></li>",
						$row['link_menu'],
						$row[$lang.'_title_menu']
						);
				}
				require($_SERVER['DOCUMENT_ROOT'].'/jbadmin/database/disconnect.php');
			?>
		</ul>
	</div>
</div>