<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\Prequisitos;
use App\Http\Controllers\InstalarDaq;
use App\Http\Controllers\InstalarSnort;
use App\Http\Controllers\Actualizar;
use App\Http\Controllers\Librerias;
use App\Http\Controllers\Paquetes;
use App\Http\Controllers\Rules;
use App\Http\Controllers\Red;
use App\Models\Btn;

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
    $consulta = Btn::first();

    return view('inicio',[
        'consulta'    => $consulta,
    ]);
})->middleware('auth');



Route::get('/correrRegla', function () {
    return view('correrRegla');
})->middleware('auth');


Route::get('/rules',                            [Rules::class, 'index']);
Route::post('regla',                            [Rules::class, 'store']);
Route::get('/instalardaq',                      [InstalarDaq::class, 'index']);
Route::get('/instalarsnort',                    [InstalarSnort::class, 'index']);

Route::get('/actualizar',                       [Actualizar::class, 'index']);
Route::get('/librerias',                        [Librerias::class, 'index'])->middleware('auth');
Route::get('/descargar',                        [Paquetes::class, 'index'])->middleware('auth');
Route::get('/requisitos',                       [Prequisitos::class, 'index'])->middleware('auth');
Route::get('/configurarweb',                    [Red::class, 'index'])->middleware('auth');


Route::middleware(['auth:sanctum', 'verified'])->get('/dashboard', function () {
    return view('dashboard');
})->name('dashboard');
