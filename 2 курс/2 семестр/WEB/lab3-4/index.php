<html lang="en">

<?php

require_once './connection_to_bd.php'; // подключение ядра
// подключение к бд
$db = new FITNESSTIME();
$db->connect();

switch ($_GET["page_type"]) {
    case "catalog":
        include ("catalog.php");
        break;
    case "about":
        include ("about.php");
        break;
    case "main":
        include ("main.php");
        break;
    default:
        include ("main.php");
        break;
}

$db->close();
?>

</html>