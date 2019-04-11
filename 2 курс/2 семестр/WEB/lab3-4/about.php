<?php

require_once './connection_to_bd.php'; // подключение ядра
$db = new FITNESSTIME();

$query = "SELECT * FROM pages WHERE page_type='about' LIMIT 1";

$db->run($query);
$db->fetch();

$id = $db->data["page_id"];
$alias = $db->data["page_type"];
$title = $db->data["page_name"];

$query = "SELECT text FROM content WHERE page_id = $id";
$db->run($query);
$db->fetch();

$component =$db-> data["text"];

// если страница не найдена в бд
if (!$id) {
    $title = "Страница не найдена";
    $component = "ОШИБКА 404! Данной страницы не существует";
}

include ("templ.php");
$db->stop();
