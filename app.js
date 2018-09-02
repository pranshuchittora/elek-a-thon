let PORT = 'ACM4';

var express = require('express');
var app = express();
var server = app.listen(8001, () => { //Start the server, listening on port 8001.
    console.log("Listening to requests on port 8001...");
})
var io = require('socket.io')(server);
app.use(express.static('public')); //Send index.html page on GET /

const SerialPort = require('serialport');
const Readline = SerialPort.parsers.Readline;
const port = new SerialPort('/dev/tty' + PORT);
const parser = port.pipe(new Readline({ delimiter: '\n' })); //Read the line only when new line comes.


parser.on('data', (serialdata) => { //Read data

    console.log(serialdata);
    let strOut = serialdata.split(" ");
    io.sockets.emit('temp', { xacc: strOut[0], yacc: strOut[1], zacc: strOut[2], resacc: strOut[3], yaw: strOut[4], roll: strOut[5], pitch: strOut[6] });
});

io.on('connection', (socket) => {
    console.log("Someone connected."); //show a log as a new client connects.
})


