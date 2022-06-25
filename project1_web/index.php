<?php 
    $conn = mysqli_connect("localhost","root","","esp32");
    $sql = "SELECT * FROM dht11";
    $execute = mysqli_query($conn, $sql);
    $result = mysqli_fetch_all($execute);
    $c = count($result);
    if ($c > 50){
        $sql2 = "DELETE FROM `dht11`";
        $execute2 = mysqli_query($conn, $sql2);
    }
?>
<!DOCTYPE html>
<html>
<head>
        <title>ESP32 PROJECTS 2022 !!!!!!</title>
        <meta charset="utf-8">
        <meta http-equiv="refresh" content="4">
        <meta name="viewpoint" content="width=device-width, initial-scale=1.0">
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Kanit:wght@300&display=swap" rel="stylesheet">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</head>
<style>
table {
    width: 100%;
}
table, th, td {
    border: 1px solid black;
    border-collapse: collapse;
}
*{
    font-family: 'Kanit', sans-serif;
    font-size: 110%;
    text-align: center;
    padding-top: 20px;
    padding: 10px;
}
</style>

<body>
<h1>ตารางแสดงผล เวลา อุณหภูมิ ความชื้น ของอากาศผ่าน ESP32</h1>
<h3>Made by MacTheDev 2022.</h3>
<table>
  <tr>
    <th>เวลา</th>
    <th>อุณหภูมิ</th>
    <th>ความชื้น</th>
  </tr>
  <?php 
     for ($i=0;$i<$c;$i++){
        echo "<tr>
       <td>".$result[$i][2]."</td>
       <td>".$result[$i][1]."</td>
       <td>".$result[$i][0]."</td>
     </tr>";
    }
  ?>
</table>

</body>
</html>
