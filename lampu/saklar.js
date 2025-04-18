function saklar(action, lamp) {
    let toggle1 = document.getElementById("default-toggle1");
    let toggle2 = document.getElementById("default-toggle2");
    let toggle3 = document.getElementById("default-toggle3");
    let lampu1 = document.getElementById("lampu1");
    let lampu2 = document.getElementById("lampu2");
    let lampu3 = document.getElementById("lampu3");

    if (toggle1.checked) {
        lampu1.src = "Gambar/images/thumb_320__1_-removebg-preview.png";
    } else {
      lampu1.src = "Gambar/images/thumb_320-removebg-preview.png";
    }

    if (toggle2.checked) {
      lampu2.src = "Gambar/images/thumb_320__1_-removebg-preview.png";
    } else {
    lampu2.src = "Gambar/images/thumb_320-removebg-preview.png";
    }

    if (toggle3.checked) {
      lampu3.src = "Gambar/images/thumb_320__1_-removebg-preview.png";
    } else {
    lampu3.src = "Gambar/images/thumb_320-removebg-preview.png";
    }


}
