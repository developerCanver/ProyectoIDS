<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateBtnsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('btns', function (Blueprint $table) {
            $table->id();
            $table->string('sistema', 45)->nullable();
            $table->string('libreria', 45)->nullable();
            $table->string('paquetes', 45)->nullable();
            $table->string('daq', 45)->nullable();
            $table->string('snort', 45)->nullable();
            $table->string('red', 45)->nullable();
            $table->string('prequisitos', 45)->nullable();
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('btns');
    }
}
