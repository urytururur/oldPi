import React, {Component} from 'react';
import {AppRegistry, Text, View} from 'react-native';

import Component5 from './components/Component5/Component5';

export default class myapp extends Component{
  render(){
    return(
      <Component5 />
    );
  }  
}

AppRegistry.registerComponent('myapp', () => myapp);