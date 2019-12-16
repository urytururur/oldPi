<?php

use Illuminate\Http\Request;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::middleware('auth:api')->get('/user', function (Request $request) {
    return $request->user();
});

Route::get('/', 'ApisController@index');

Route::get('switches', 'SwitchesController@index');
Route::get('switch/{id}', 'SwitchesController@show');
Route::post('switch', 'SwitchesController@store');
Route::put('switch/{id}', 'SwitchesController@store');
Route::delete('switch/{id}', 'SwitchesController@destroy');

Route::get('huelights', 'HuelightsController@index');
Route::get('huelight/{id}', 'HuelightsController@show');
Route::post('huelight', 'HuelightsController@store');
Route::put('huelight/{id}', 'HuelightsController@store');
Route::delete('huelight/{id}', 'HuelightsController@destroy');

//Route::resource('switches', 'SwitchesController');//->middleware('cors'); //"->middleware('cors');" GER CORS-CONTROLL, TILLH�RANDE FILER �R DENNA FIL, CORS.PHP OCH KERNEL.PHP!
//http://192.168.0.101/api/AmE3DbmI-V6GpnsBHqdG-g5NG7Xiz1AvUh8iMVt7/lights