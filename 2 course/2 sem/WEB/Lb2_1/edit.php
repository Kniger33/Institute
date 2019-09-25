<html lang="ru">
<head>
    <title>Edit</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="styles/style.css">
</head>
<?php
    if (isset($_POST['editBtnName'])) {
        $getFilmName = $_POST["editBtnName"];
        //echo "EDIT: ".$getFilmName;
    }
    if (isset($_POST['change'])) {
    $getFilmName = $_POST["change"];
    //echo "CHANGE: ".$getFilmName;
}

require 'connection.php';
// подключаемся к серверу
$link = mysqli_connect($host, $user, $password, $database)
or die("Err" . mysqli_error($link));

$query = "SELECT * FROM film  
                    WHERE film.Name = '$getFilmName'";
$result = mysqli_query($link, $query);
while ($row = mysqli_fetch_array($result))
{
    $filmName = $row["Name"];
    $idFilm = $row["idFilm"];
    $description = $row["Description"];
}

$queryImage = "SELECT image.Name FROM image
                    INNER JOIN film f ON image.Film_idFilm = f.idFilm
                        WHERE f.Name = '$getFilmName'";
$result = mysqli_query($link, $queryImage);
while ($row = mysqli_fetch_array($result))
{
    $imageName = $row["Name"];
}

$queryFilmRating = "SELECT f.Value
                            FROM filmrating f                            
                            INNER JOIN film f2 on f.Film_idFilm = f2.idFilm
                            WHERE f2.Name = '$getFilmName'";
$result = mysqli_query($link, $queryFilmRating);
while ($row = mysqli_fetch_array($result))
{
    $ratingValue = $row["Value"];
}
$queryEPName = "SELECT evaluationportal.Name
                        FROM evaluationportal
                        INNER JOIN filmrating f ON evaluationportal.idEvaluationPortal = f.EvaluationPortal_idEvaluationPortal
                        INNER JOIN film f2 on f.Film_idFilm = f2.idFilm
                        WHERE f2.Name = '$getFilmName'";
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
        <div>
            <?php
            echo $filmName;
            ?>
        </div>
    </a>
    <form method="post" >
        <textarea name="newDescription" cols="100" rows="10"/><?=$description?></textarea><br>
        <input type="text" name="newEP" value=<?=$portalName?> /> :
        <input type="text" name="newRating" value=<?=$ratingValue?> />
        <button name="change" value=<?=$idFilm?> class="button_edit">
            Изменить
        </button>
    </form>
    <b style="display: block; margin: 10px">
    </b>

</div>

<?php
if (isset($_POST['change']))
{
    $newEP = $_POST['newEP'];
    $newRating = $_POST['newRating'];
    $newDescription = $_POST['newDescription'];
    $idFilm = $_POST['change'];

    $queryFN = "SELECT Name FROM image                            
                        WHERE Film_idFilm = $idFilm";
    $result = mysqli_query($link, $queryFN);
    while ($row = mysqli_fetch_array($result))
    {
        $nameFilm = $row["Name"];
    }
    //echo "FN: ".$nameFilm;
    if($newDescription != null)
        $query = "UPDATE film SET Description = '".$newDescription."' WHERE idFilm = '".$idFilm."'";
    mysqli_query($link, $query);

    if($newRating != null)
        $query = "UPDATE filmrating SET Value = $newRating WHERE Film_idFilm = $idFilm";
    mysqli_query($link, $query);

    if($newDescription != null)
        $query = "UPDATE evaluationportal SET Name = '".$newEP."'
        WHERE idEvaluationPortal = (SELECT EvaluationPortal_idEvaluationPortal FROM filmrating WHERE Film_idFilm = $idFilm)";
    mysqli_query($link, $query);
    //echo "QUERY: ".$query;
    header("Location: ".$nameFilm.".php");
}
mysqli_close($link);
?>

