const path = require('path');

var APP_DIR = path.resolve(__dirname)

console.log(APP_DIR);
module.exports = {
	context: __dirname,
	entry: APP_DIR + '/index.jsx',//path.resolve(APP_DIR + 'index.jsx'),
	output: {
		path: APP_DIR,//"index.jsx",// path.resolve(__dirname),
		filename: "bundle.js"
},
module: {
	rules: [
		{
			test: /\.jsx\?$/,
			exclude: /(node_modules)/,
			use: {
				loader: 'babel-loader', 
				query: {
 					presets: ['env', 'react']
				}
			},
		}
	]
},
devtool: 'source-map',
resolve: {
	extensions: [".js", ".jsx", "*"]
	}
};
