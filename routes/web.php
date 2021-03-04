<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\Descargar;
use App\Http\Controllers\InstalarDaq;
use App\Http\Controllers\InstalarSnort;
use App\Http\Controllers\Actualizar;
use App\Http\Controllers\Rules;
/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('inicio');
});
Route::get('/descargar', [Descargar::class, 'index']);

Route::get('/rules', [Rules::class, 'index']);
Route::post('regla', [Rules::class, 'store']);
Route::get('/instalardaq', [InstalarDaq::class, 'index']);
Route::get('/instalarsnort', [InstalarSnort::class, 'index']);
Route::get('/actualizar', [Actualizar::class, 'index']);


