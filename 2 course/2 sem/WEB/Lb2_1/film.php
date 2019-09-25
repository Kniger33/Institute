<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="styles/style.css">
</head>

<body>
    <?php
//        require 'header.php';
//        require 'navigation.php';
//        require 'menu.php';
        $link = mysqli_connect('127.0.0.1:3306', 'root', '1234', 'web')
        or die("Err" . mysqli_error($link));

        $idFilm = $_POST['idFilm'];
        $queryfilmInfo = "SELECT * FROM film 
                            WHERE film.idFilm = $idFilm";

    ?>
    <div class="content_class_films">
        <img src="images/<?=$_GET["film"];?>.jpg" alt="poster" width="222" height="333" align="left" vspace="10px" hspace="10px">
        <b style="display: block; margin: 10px">
            <? echo "ASD"; ?>
        </b>
    </div>

    <?php
        require 'bottom.php';
    ?>
</body>
</html>