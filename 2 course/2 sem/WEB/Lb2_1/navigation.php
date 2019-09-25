<div class="navigation_class">
    <?php
        $links = array(
                    'Главная' => 'index.php',
                    'Каталог' => 'catalog.php',
                    'О нас' => 'about.php',
                    'Контакты' => 'contact.php'
        );
        foreach ($links as $key => $value)
        {
            echo "<div class=\"nav_link_block\">
                    <a href=\"$value\" class=\"nav_link\">$key</a>
                    </div>
                ";
        }

    ?>

</div>
<div class="clear">
</div>