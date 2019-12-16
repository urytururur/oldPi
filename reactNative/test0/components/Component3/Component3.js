import React, {Component} from 'react';
import {AppRegistry, Text, View, TextInput, StyleSheet, Switch} from 'react-native';

export default class Component3 extends Component{
    constructor(){
        super();
        this.state = {
            textValue: 'Hello',
            switchValue: false
        }
    }

    textChanged(value){
        this.setState({
            textValue: value
        });
    }

    onSubmit(){
        console.log("Input submitted...")
    }

    onSwitchChange(value){
        this.setState({
            switchValue: value
        });
    }

  render(){
    return(
      <View>
        <TextInput
            style={styles.position}
            placeholder="Enter Text"
            value={this.state.textValue}
            onChangeText={(value) => this.textChanged(value)}
            onSubmitEditing={this.onSubmit}
        />
        <Text>{this.state.textValue}</Text>
        <Switch
            value={this.state.switchValue}
            onValueChange={(value) => this.onSwitchChange(value)}
        />
      </View>
    );
  }  
}

const styles = {
    position: {
        paddingTop: 100
    }
}

AppRegistry.registerComponent('Component3', () => Component3);