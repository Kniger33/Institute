<?php

?>

<!DOCTYPE html>
<html lang="ru">
<head>
    <title>Registration</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="../../styles/style.css">
</head>

<body>
    <div class="header">
        <h2>Регистрация</h2>
    </div>

    <form class="form-content" method="post" action="register.php">
        <!--display validation errors here-->
        <?php require '../errors.php'; ?>
        <div class="input-group">
            <label>Логин</label>
            <input type="text" name="username" value="<?php echo $username;?>">
        </div>
        <div class="input-group">
            <label>Почта</label>
            <input type="text" name="email" value="<?php echo $email;?>">
        </div>
        <div class="input-group">
            <label>Пароль</label>
            <input type="password" name="password_1">
        </div>
        <div class="input-group">
            <label>Подтверждение пароля</label>
            <input type="password" name="password_2">
        </div>
        <div class="input-group">
            <button type="submit" name="register" class="btn">Зарегистрироваться</button>
        </div>
        <p>
            Уже зарегистрированы? <a href="../authorization/login.php">Войти</a>
        </p>
        <p>
            <a href="/index.php">На главную</a>
        </p>
    </form>

</body>
</html>