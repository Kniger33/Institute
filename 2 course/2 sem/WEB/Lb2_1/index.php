<!DOCTYPE html>
<html lang="ru">
<head>
    <title>Main</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="styles/style.css">
</head>

<body>
    <?php
        require 'header.php';
        require 'navigation.php';
    ?>

    <div class="content_class">
        <p style="padding-left: 20px">Главная страница</p>
        <?php if (isset($_SESSION['username'])): ?>
            <p style="padding-left: 20px">Welcome <strong><?php echo $_SESSION['username'] ?></strong></p>
        <?php endif; ?>
        <p class="text" id="time-to"></p>
        <a class="btn-modal" id="modal-wnd">Modal window</a>
        <div class="modal" id="modal-text">
            <p>Game of thrones 8 season 5 episode</p>
            <a class="btn-modal" id="close-modal-wnd">
                Закрыть
            </a>
        </div>
        <div class="overlay" id="overlay-modal"></div>
        <script>
            document.addEventListener("DOMContentLoaded", () => {
                let modalOpen = document.getElementById("modal-wnd");
                let modalElem = document.getElementById("modal-text");
                let modalClose = document.getElementById("close-modal-wnd");
                let overlay = document.getElementById("overlay-modal");

                modalOpen.addEventListener("click", () => {
                    overlay.classList.add("active");
                    modalElem.classList.add("active");
                });
                modalClose.addEventListener("click", () => {
                    modalElem.classList.remove("active");
                    overlay.classList.remove("active");
                });
            })
        </script>
        <script src="index.js"></script>
    </div>

    <?php
        require 'bottom.php';
    ?>
</body>
</html>