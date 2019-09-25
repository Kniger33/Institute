let time = document.getElementById("time-to");
let endDate = new Date("2019-05-13T23:59:59");

tick = () => {
    let timeNow = new Date(Date.now());
    let days = Math.abs(endDate.getDate() - timeNow.getDate());
    let hours = Math.abs(endDate.getHours() - timeNow.getHours());
    let minutes = Math.abs(endDate.getMinutes() - timeNow.getMinutes());
    let seconds = Math.abs(endDate.getSeconds() - timeNow.getSeconds());

    if (minutes !== 0) {
        hours--;
    }

    time.innerHTML =  `Days: ${days}, Hours: ${hours}, Minutes: ${minutes}, Seconds: ${seconds}`;
};

setInterval(tick, 1000);