<?php include '../server.php'; ?>
<!DOCTYPE html>
<html lang="ru">
<head>
    <title>Registration</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="../../styles/style.css">
</head>

<body>
<div class="header">
    <h2>Авторизация</h2>
</div>

<form class="form-content" method="post" action="login.php">
    <!--display validation errors here-->
    <?php require '../errors.php'; ?>
    <div class="input-group">
        <label>Логин</label>
        <input type="text" name="username">
    </div>
    <div class="input-group">
        <label>Пароль</label>
        <input type="password" name="password">
    </div>
    <div class="input-group">
        <button type="submit" name="login" class="btn">Войти</button>
    </div>
    <p>
        Еще не зарегистрированы? <a href="../registration/register.php">Регистрация</a>
    </p>
    <p>
        <a href="/index.php">На главную</a>
    </p>
</form>

</body>
</html>