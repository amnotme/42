// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   webpack.config.js                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: leopoldohernandez <Leo@42.us.org>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/05/14 02:45:48 by leopoldoh         #+#    #+#             //
//   Updated: 2018/05/14 02:47:29 by leopoldoh        ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


const path = require('path');

module.exports = {
  context: __dirname,
  entry: "./index.jsx",
  output: {
    path: path.resolve(__dirname),
    filename: "bundle.js"
  },
  module: {
    rules: [
      {
        test: /\.jsx?$/,
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