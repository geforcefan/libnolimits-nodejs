var SegfaultHandler = require('segfault-handler');

SegfaultHandler.registerHandler("crash.log"); // With no argument, SegfaultHandler will generate a generic log file name

// Optionally specify a callback function for custom logging. This feature is currently only supported for Node.js >= v0.12 running on Linux.
SegfaultHandler.registerHandler("crash.log", function(signal, address, stack) {
    // Do what you want with the signal, address, or stack (array)
    // This callback will execute before the signal is forwarded on.
});

console.log("Started");
const NoLimits = require('.').default;

const Park = new NoLimits.NoLimits2.Park();

for(var x = 0; x < Park.Terrain.VertexDimX; x++) {
    for(var y = 0; y < Park.Terrain.VertexDimY; y++) {
        Park.Terrain.setHeightAtVertex(x, y, 30.0);
    }
}

var resourceFile = new NoLimits.NoLimits2.ResourceFile();
resourceFile.Id = "0ABC";
resourceFile.Path = "Test";

var script = new NoLimits.NoLimits2.Script();
script.insertResourceFile(resourceFile);
script.PrivateVirtualMachine = true;
script.ClassPath = "Hey Class";

var coaster = new NoLimits.NoLimits2.Coaster();
coaster.insertScript(script);
coaster.Name = "Ercan Coaster";

Park.insertCoaster(coaster);

Park.save("/Users/ercanakyurek/Desktop/TestCoaster/Test.nl2park");

console.log(script);
