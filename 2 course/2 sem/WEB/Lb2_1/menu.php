<div class="menu_class">
    <?php
        $filmsMenu = ['Форсаж 8' => 'fast_and_furious.php',
                        'Алита: Боевой ангел' => 'alita.php',
                        'ЛЕГО Фильм-2' => 'lego.php'];
        foreach ($filmsMenu as $key => $value)
            echo "<a href=\"$value\" class=\"film_link\">$key</a>";
    ?>
</div>