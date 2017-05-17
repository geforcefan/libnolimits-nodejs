var SegfaultHandler = require('segfault-handler');

SegfaultHandler.registerHandler("crash.log"); // With no argument, SegfaultHandler will generate a generic log file name

// Optionally specify a callback function for custom logging. This feature is currently only supported for Node.js >= v0.12 running on Linux.
SegfaultHandler.registerHandler("crash.log", function(signal, address, stack) {
    // Do what you want with the signal, address, or stack (array)
    // This callback will execute before the signal is forwarded on.
});


const NoLimits = require('.').default;

const Park = new NoLimits.NL2.Park();

for(var x = 0; x < Park.Terrain.VertexDimX; x++) {
    for(var y = 0; y < Park.Terrain.VertexDimY; y++) {
        Park.Terrain.setHeightAtVertex(x, y, 30.0);
    }
}

Park.save("/Users/ercanakyurek/Desktop/TestCoaster/Test.nl2park");

console.log(Park);
