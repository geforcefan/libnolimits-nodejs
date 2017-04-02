var SegfaultHandler = require('segfault-handler');

SegfaultHandler.registerHandler("crash.log"); // With no argument, SegfaultHandler will generate a generic log file name

// Optionally specify a callback function for custom logging. This feature is currently only supported for Node.js >= v0.12 running on Linux.
SegfaultHandler.registerHandler("crash.log", function(signal, address, stack) {
    // Do what you want with the signal, address, or stack (array)
    // This callback will execute before the signal is forwarded on.
});


const NoLimits = require('./build/Release/nolimits');
//const Park = new NoLimits.NL2.Park("/Users/ercanakyurek/Desktop/newpark/parks/Script Park/Script Park.nl2park");
const Park = new NoLimits.NL2.Park("/Users/ercanakyurek/Desktop/newpark/parks/Hydra/Hydra.nl2park");

console.log(Park.Coaster[0].Track[1].Segment);

console.log(NoLimits.NL2.WoodenSupportGenerator);
