<?php
  if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $data = $_POST["data"];
    $arr = explode("/", $data);
    $hum = $arr[0];
    $tem = $arr[1];
    date_default_timezone_set('Asia/Bangkok');
    $time = date('d-m-y h:i:s');
    $conn = mysqli_connect("localhost","root","","esp32");
    $sql = "INSERT INTO dht11 (hum, tem, time) VALUES ('$hum', '$tem', '$time')";
    $execute = mysqli_query($conn, $sql);
 }
 else {
    $myfile = fopen("error.txt", "w") or die("Unable to open file!");
    $txt = "error !!!!\n";
    fwrite($myfile, $txt);
    fclose($myfile);
 }


?>
