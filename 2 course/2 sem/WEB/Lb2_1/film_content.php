<div class="content_class_films">
    <?php
        require 'connection.php';
        // подключаемся к серверу
        $link = mysqli_connect('127.0.0.1:3306', 'root', '1234', 'web')
        or die("Err" . mysqli_error($link));

        $filmNamesQuery = "SELECT Name FROM film";
        $namesResult = mysqli_query($link, $filmNamesQuery);

        for($i = 0; $i < 2; $i++) {
            ?>
                <a href="" class="film_block" id=idFilmBlock.<?=$i?>>
                    <div id=idImage.<?=$i?>>

                    </div>
                    <div class="film_text" id=idFilm_text.<?=$i?>>

                    </div>
                    <div class="film_rating" id=idFilm_rating.<?=$i?>>

                    </div>
                    <div class="film_tags" id=idFilm_genres.<?=$i?>>

                    </div>
                </a>
            <?php
        }
    require 'paging.html';
    ?>
</div>


