<?php
    class Film
    {
        public $idFilm, $filmName, $description, $ageLimit, $duration, $releaseDate,
            $imageName, $ratingValue, $portalName, $genres;

        function __construct($idFilm, $filmName, $description,
                             $ageLimit, $duration, $releaseDate,
                             $imageName, $ratingValue, $portalName,
                             $genres)
        {
            $this->idFilm = $idFilm;
            $this->filmName = $filmName;
            $this->description = $description;
            $this->ageLimit = $ageLimit;
            $this->duration = $duration;
            $this->releaseDate = $releaseDate;
            $this->imageName = $imageName;
            $this->ratingValue = $ratingValue;
            $this->portalName = $portalName;
            $this->genres = $genres;
        }

        function getGenre($idGenre)
        {
            return $this->genres[$idGenre];
        }
    }
?>
<?php
    $link = mysqli_connect('127.0.0.1:3306', 'root', '1234', 'web')
    or die("Err" . mysqli_error($link));

    $films = array();

    $queryIdFilms = "SELECT idFilm FROM film";
    $resultId = mysqli_query($link, $queryIdFilms);

while ($rowCurFilm = mysqli_fetch_row($resultId))
{
    $queryMainInfo = "SELECT * FROM film
                                WHERE film.idFilm = $rowCurFilm[0]";
    $result = mysqli_query($link, $queryMainInfo);
    while ($row = mysqli_fetch_array($result))
    {
        $filmName = $row["Name"];
        $description = $row["Description"];
        $ageLimit = $row["AgeLimit"];
        $duration = $row["Duration"];
        $releaseDate = $row["ReleaseDate"];
    }
    $queryImage = "SELECT Name FROM image
                            WHERE Film_idFilm = $rowCurFilm[0]";
    $result = mysqli_query($link, $queryImage);
    while ($row = mysqli_fetch_array($result))
    {
        $imageName = $row["Name"];
    }
    $queryFilmRating = "SELECT filmrating.Value FROM filmrating 
                                 WHERE Film_idFilm = $rowCurFilm[0]";
    $result = mysqli_query($link, $queryFilmRating);
    while ($row = mysqli_fetch_array($result))
    {
        $ratingValue = $row["Value"];
    }
    $queryEPName = "SELECT evaluationportal.Name
                            FROM evaluationportal
                            INNER JOIN filmrating f ON evaluationportal.idEvaluationPortal = f.EvaluationPortal_idEvaluationPortal
                            WHERE f.Film_idFilm = $rowCurFilm[0]";
    $result = mysqli_query($link, $queryEPName);
    while ($row = mysqli_fetch_array($result))
    {
        $portalName = $row["Name"];
    }
    $queryGenre = "SELECT genre.Name FROM genre
                        INNER JOIN film_has_genre fhg on genre.idGenre = fhg.Genre_idGenre
                        WHERE fhg.Film_idFilm = $rowCurFilm[0]";
    $resultG = mysqli_query($link, $queryGenre);
    $i = 0;
    while ($row = mysqli_fetch_array($resultG))
    {
        $genres[$i] = $row["Name"];
        $i++;
    }

    $films[] = new Film($rowCurFilm[0], $filmName, $description, $ageLimit,
        $duration, $releaseDate, $imageName, $ratingValue, $portalName, $genres);
}
    $json = json_encode($films, JSON_UNESCAPED_UNICODE | JSON_NUMERIC_CHECK );
    echo $json;
//        echo "<pre>";
//        print_r($films[1]->idFilm);
//        echo "</pre>";
?>