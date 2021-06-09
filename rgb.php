<!DOCTYPE html>
<html>
<title>LIVE</title>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="refresh" content="5;url=rgb.php">
</head>
<body>

<h1 style="text-align:center;">RGB Data</h1>

<div class="tabel_layout">
<table style="width:50%" border="1"align="center">
<colgroup>
<col width="25%">
<col width="25%">
<!--<col width="25%">
<col width="25%">-->
</colgroup>

<?php
$conn = mysqli_connect("localhost","root","1234","smart_factory");
$result = mysqli_query($conn,"SELECT * FROM test");

echo "<th> COLOR </th>";
echo "<th> EA </th>";
//echo "<tr style=color:Blue;> BLUE </tr>";
//echo "<tr> TOTAL </tr>";


while($row = mysqli_fetch_array($result)){
echo "<tr>";
echo "<th>" . $row[0] . "</th>";
echo "<th>" . $row[1] . "</th>";
echo "</tr>";
//echo "<th>" . $row[2] . "</th>";
//echo "<th>" . $row[3] . "</th>";
//echo "</tr>";

}
mysqli_close($conn);
?>
</table>
</div>
<style>
.button {
background-color:black;
border: none;
color: white;
padding: 15px 30px;
text-align: center;
text-decoration: none;
display: inline-block;
font-size: 16px;
margin: 4px 2px;
cursor: pointer;
float: right;
}
</style>
<div align="center">
<button><a href ="main.html">Back</a></button> 
<button><a href ="storage.php">DATA</a></button>
</div>
</body>
</html>
