<script setup>
  import { ref } from 'vue'
  
  var Longitude = null
  
  // Connecting to ROS
  // -----------------

  var ros = new ROSLIB.Ros({
    url : 'ws://192.168.43.166:9090'
  });

  ros.on('connection', function() {
    console.log('Connected to websocket server.');
  });

  ros.on('error', function(error) {
    console.log('Error connecting to websocket server: ', error);
  });

  ros.on('close', function() {
    console.log('Connection to websocket server closed.');
  });
  
  // Subscribing to a Topic
  // ----------------------

  var listener = new ROSLIB.Topic({
    ros : ros,
    name : '/mti/position_lonLat',
    messageType : 'xsens_msgs/PosPL'
  });

  listener.subscribe(function(message) {
    //console.log('Received message on ' + listener.name + ': ' + message.longitude);
    Longitude = message.longitude
    console.log(Longitude)
    //listener.unsubscribe();
  });
  
</script>

<template>
  <h1>Simple roslib Example</h1>
  <p>Check your Web Console for output.</p>
  <p>{{Longitude}}</p>
</template>
