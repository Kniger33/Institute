<!DOCTYPE html>
<html lang="ru">
<head>
    <title>Alita</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="styles/style.css">
</head>

<body>
    <?php
        require 'header.php';
        require 'navigation.php';
        require 'menu.php';
        require 'connection.php';
        // подключаемся к серверу
        $link = mysqli_connect($host, $user, $password, $database)
            or die("Err" . mysqli_error($link));

        $query = "SELECT * FROM film  
                    WHERE film.Name = 'Алита: Боевой ангел'";
        $result = mysqli_query($link, $query);
        while ($row = mysqli_fetch_array($result))
        {
            $idFilm = $row["idFilm"];
            $filmName = $row["Name"];
            $description = $row["Description"];
            $ageLimit = $row["AgeLimit"];
            $duration = $row["Duration"];
            $releaseDate = $row["ReleaseDate"];
        }

        $queryImage = "SELECT image.Name FROM image
                    INNER JOIN film f ON image.Film_idFilm = f.idFilm
                        WHERE f.Name = 'Алита: Боевой ангел'";
        $result = mysqli_query($link, $queryImage);
        while ($row = mysqli_fetch_array($result))
        {
            $imageName = $row["Name"];
        }

        $queryFilmRating = "SELECT f.Value
                            FROM filmrating f                            
                            INNER JOIN film f2 on f.Film_idFilm = f2.idFilm
                            WHERE f2.Name = 'Алита: Боевой ангел'";
        $result = mysqli_query($link, $queryFilmRating);
        while ($row = mysqli_fetch_array($result))
        {
            $ratingValue = $row["Value"];
        }
        $queryEPName = "SELECT evaluationportal.Name
                        FROM evaluationportal
                        INNER JOIN filmrating f ON evaluationportal.idEvaluationPortal = f.EvaluationPortal_idEvaluationPortal
                        INNER JOIN film f2 on f.Film_idFilm = f2.idFilm
                        WHERE f2.Name = 'Алита: Боевой ангел'";
        $result = mysqli_query($link, $queryEPName);
        while ($row = mysqli_fetch_array($result))
        {
            $portalName = $row["Name"];
        }

    ?>
    <div class="content_class_films">
        <a>
            <div>
                <img src="images/<?=$imageName?>.jpg" width="222" height="333" align="left" vspace="10px" hspace="10px">
            </div>
            <div class="film_rating">-->
                Рейтинг <?=$portalName?>: <?=$ratingValue?>
            </div>

            <div class="film_tags">
                <?php
                $queryGenre = "SELECT genre.Name
                        FROM genre
                        INNER JOIN film_has_genre fhg on genre.idGenre = fhg.Genre_idGenre
                        INNER JOIN film f on fhg.Film_idFilm = f.idFilm
                        WHERE f.Name = 'Алита: Боевой ангел'";
                $resultG = mysqli_query($link, $queryGenre);
                $i = 0;
                while ($row = mysqli_fetch_array($resultG))
                {
                    echo ''.$row["Name"];
                    if($i == mysqli_num_rows($resultG) - 1)
                    {
                        break;
                    }
                    echo ', ';
                    $i++;
                }
                ?>
            </div>
            <b>
                <?php
                    echo $filmName;
                ?>
            </b>
        </a>
        <p style="display: block; margin: 10px">
            <?php
            echo $description;
            // закрываем подключение
            mysqli_close($link);
            ?>
        </p>
        <?php if(isset($_SESSION['root']) and $_SESSION['root'] == 'admin'): ?>
            <div class="edit">
                <form method="post" action="edit.php" class="form-edit">
                    <br><button type="submit" name="editBtnName" value='Алита: Боевой ангел' class="button_edit">
                        Редактирование
                    </button>
                </form>
            </div>
        <?php endif; ?>
        <?php if(isset($_SESSION['root']) and $_SESSION['root'] == 'user'): ?>
            <div class="edit">
                <form method="post" action="buy_ticket.php" class="form-edit">
                    <br><button type="submit" name="btnBuyTicket" value=<?= $idFilm ?> class="button_edit">
                        Купить билет
                    </button>
                </form>
            </div>
        <?php endif; ?>
    </div>

    <?php
        require 'bottom.php';
    ?>
</body>
</html>