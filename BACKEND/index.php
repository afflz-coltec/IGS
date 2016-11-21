<?php
require("php_serial.class.php");
$url = 'URL';

// include("php_serial.class.php");

// Let's start the class
$serial = new phpSerial();

// First we must specify the device. This works on both Linux and Windows (if
// your Linux serial device is /dev/ttyS0 for COM1, etc.)
$serial->deviceSet("/dev/ttyACM0");

// Set for 9600-8-N-1 (no flow control)
$serial->confBaudRate(9600); //Baud rate: 9600
$serial->confParity("none");  //Parity (this is the "N" in "8-N-1")
$serial->confCharacterLength(8); //Character length     (this is the "8" in "8-N-1")
$serial->confStopBits(1);  //Stop bits (this is the "1" in "8-N-1")
$serial->confFlowControl("none");

// Then we need to open it
$serial->deviceOpen();

$count = 0;
while (true){

  $count++;

  //camera_scripts

  exec('/server/camera_scripts/fscam.sh');


  $data = file_get_contents($_FILES['imagem']['tmp_name']);
  //var_dump($_FILES['imagem']);
  $img = base64_encode($data);

  // Read data
  $read = $serial->readPort();
  $data = array('sensores' => $read, 'image' => $img);


  $options = array(
    'http' => array(
      'header'  => "Content-type: application/x-www-form-urlencoded\r\n",
      'method'  => 'POST',
      'content' => http_build_query($data),
    )
  );

  $context  = stream_context_create($options);
  $result = file_get_contents($url, false, $context);
  var_dump($result);

  // Print out the data
  echo $read;


}

// If you want to change the configuration, the device must be closed.
$serial->deviceClose();
?>
